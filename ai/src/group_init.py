from ai.src.player import Player, EnumObject, EnumHeader, ALL
from ai.src.handle_packets import duplicate

def find_boss(player: Player):
    player.broadcast(player.uuid + " " + EnumHeader.ASKBOSS.value + " " + ALL + " Who", False)
    player.take(EnumObject.LINEMATE.value, False)
    player.take(EnumObject.FOOD.value, False)

    if player.boss != 0:
        player.boss = 1
        print("I AM THE BOSS\n")
        if (player.slot > 0):
            for _ in range(0, player.slot):
                duplicate(player.args)
                player.wait_broadcast()
    else:
        print("YES SIR", flush=True)