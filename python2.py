import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(("192.168.1.72", 5005))
while True:
    x, addr = sock.recvfrom(1024)
    y, addr = sock.recvfrom(1024)
    print("x:", int(bytes.decode(x)), "y:", int(bytes.decode(y)))
