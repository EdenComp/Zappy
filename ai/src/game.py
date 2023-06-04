import socket
import os

from ai.src.player import Player, EnumObject, EnumHeader, EnumDirection
from ai.src.handle_packets import duplicate

def find_boss(player: Player):
    player.broadcast(EnumHeader.ASKBOSS.value + " Who\n")
    player.look()
    player.take(EnumObject.FOOD.value)

    if player.boss != 0:
        player.boss = 1
    if (player.space == True):
        duplicate(player.args)
        player.space = False
        player.wait_answer()

def locate(player: Player):
    print("player pos: ", player.pos_boss)
    if (player.pos_boss == 0):
        player.broadcast(EnumHeader.IMHERE.value +" IMHERE\n")
        print ("IMHERE\n")
        return True
    elif (player.pos_boss == 1 or player.pos_boss == 2 or player.pos_boss == 8):
        player.move()
        print("IMOVE\n")
    elif (player.pos_boss == 4 or player.pos_boss == 5 or player.pos_boss == 3):
        player.turn(EnumDirection.LEFT.value)
        print("LEFT\n")
    elif (player.pos_boss == 6 or player.pos_boss == 7):
        player.turn(EnumDirection.RIGHT.value)
        print("RIGHT\n")
    player.wait_answer(True)
    return False

def join_boss(player: Player):
    if player.boss == 1:
        while (player.nbr_ai > 0):
            print("je gueule {}\n".format(player.nbr_ai))
            player.broadcast(EnumHeader.IMBOSS.value + " IMBOSS\n")
    else:
        while (locate(player) == False):
            pass

# def get_mineral(player: Player):
#     if player.boss == 1:
#         print (player.look())
#     else:
#         for _ in range(0, 3):
#             player.move()
#         player.look()
#         player.turn(EnumDirection.LEFT.value)

def game_loop(sock: socket.socket, args):
    player = Player(sock, args)
    find_boss(player)
    join_boss(player)
    while (1):
        pass
    # get_mineral(player)
    sock.close()
