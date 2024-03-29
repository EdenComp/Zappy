from typing import Final
import socket
import os
import signal

def signal_handler(signal, frame):
    print("CTRL-C detected, exiting")
    exit(0)

signal.signal(signal.SIGINT, signal_handler)

class BadConnectionException(Exception):
    pass

def get_socket(port: int, ip = "127.0.0.1"):
    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((ip, port))
        print("Connexion établie avec le serveur sur le port {}".format(port))
        return sock
    except socket.error as e:
        raise BadConnectionException("Erreur lors de la création de la socket : " + str(e))

def receive_packet(sock: socket.socket):
    try:
        donnees = sock.recv(8192)
        pass
    except KeyboardInterrupt:
        exit(0)
    if not donnees:
        from ai.src.player import ErrorConnection
        raise ErrorConnection("Error: Server closed")
    donnees = donnees.split(b'\n')
    for i, x in enumerate(donnees):
        donnees[i] = x.decode()
    return donnees

def duplicate(args):
    pid = os.fork()
    if pid < 0:
        return 84
    if pid == 0:
        return 0
    os.execve("./zappy_ai", ["./zappy_ai", "-p", str(args.port), "-n", args.name,], os.environ)
