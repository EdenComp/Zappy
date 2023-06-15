from ai.src.player import Player, EnumObject

def dump_item(player: Player):
    inventory = player.inventory()
    if (inventory == False or len(inventory) == 0):
        return False
    for i in range(1, len(inventory)):
        for _ in range(0, inventory[i]):
            if i == 1:
                if (player.set(EnumObject.LINEMATE) == False):
                    return False
            if i == 2:
                if (player.set(EnumObject.DERAUMERE) == False):
                    return False
            if i == 3:
                if (player.set(EnumObject.SIBUR) == False):
                    return False
            if i == 4:
                if (player.set(EnumObject.MENDIANE) == False):
                    return False
            if i == 5:
                if (player.set(EnumObject.PHIRAS) == False):
                    return False
            if i == 6:
                if (player.set(EnumObject.THYSTAME) == False):
                    return False