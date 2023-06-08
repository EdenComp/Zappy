import socket
import re

from ai.src.game_start import find_boss, join_boss
from ai.src.player import Player, EnumObject
from ai.src.players.routine_ai import routine_ai
from ai.src.players.routine_boss import routine_boss

def look_item(player : Player):
    str: str = player.look()
    str = str.replace("[ ", "")
    str = str.replace(", ]", ", V,")
    str = str.replace(" ]", "")
    for i in range(0, 10):
        str = str.replace(",,", ", V,")
    list : list = str.split(", ")
    list_tmp = []
    for i in list:
        list_tmp.append(i.split(" "))
    foot_case = list_tmp.pop(0)
    return list_tmp[:3], foot_case

def dump_item(player: Player):
    inventory = player.inventory()
    for i in range(1, len(inventory)):
        for _ in range(0, inventory[i]):
            if i == 1:
                player.set(EnumObject.LINEMATE)
            if i == 2:
                player.set(EnumObject.DERAUMERE)
            if i == 3:
                player.set(EnumObject.SIBUR)
            if i == 4:
                player.set(EnumObject.MENDIANE)
            if i == 5:
                player.set(EnumObject.PHIRAS)
            if i == 6:
                player.set(EnumObject.THYSTAME)

def game_loop(sock: socket.socket, args):
    player = Player(sock, args)
    find_boss(player)
    join_boss(player)
    if player.boss == 1:
        routine_boss(player)
        pass
    else:
        routine_ai(player)
        pass
    sock.close()
