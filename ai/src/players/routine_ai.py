from ai.src.player import Player, EnumDirection, EnumObject, look_item

def first_pattern_ai(list_item: list, player: Player):
    player.move()
    for i in list_item[0]:
        player.take(i)
    player.turn(EnumDirection.LEFT)
    player.move()
    for i in list_item[1]:
        player.take(i)

def second_pattern_ai(list_item: list, player: Player):
    player.turn(EnumDirection.LEFT)
    player.move()
    player.move()
    for i in list_item[0]:
        player.take(i)
    player.turn(EnumDirection.LEFT)
    player.move()
    for i in list_item[1]:
        player.take(i)
    player.move()
    for i in list_item[2]:
        player.take(i)
    player.turn(EnumDirection.LEFT)
    player.move()
    player.move()
    for i in list_item[3]:
        player.take(i)

def look_aroud_ai(player: Player):
    list_item = []
    for _ in range(0, 3):
        player.move()
    tmp, foot_case = look_item(player)
    for i in tmp:
        list_item.append(i)
    for _ in range(0, 2):
        player.turn(EnumDirection.RIGHT)
    tmp, _ = look_item(player)
    for j in tmp:
        list_item.append(j)
    list_item.insert(0, list_item.pop())
    return list_item, foot_case

def return_to_boss(player: Player):
    player.turn(EnumDirection.LEFT)
    player.move()
    player.turn(EnumDirection.RIGHT)
    player.move()
    player.move()
    # par la suite verifier que cela n'a pas fail car il ne peux pas y avoir plus de 10 commands a gerer en meme temps cote serv

def routine_ai(player: Player):
    list_item, foot_case = look_aroud_ai(player)
    for i in foot_case:
        player.take(i)
    list_item.reverse()
    print(list_item)
    print("\n")
    print(player.inventory())
    first_pattern_ai(list_item, player)
    second_pattern_ai(list_item[2:], player)
    return_to_boss(player)
    print(player.inventory())