import asyncio
import json
import websockets
import socket

IP = "192.168.1.72"


async def connect(websocket, path):
    async for message in websocket:
        data = json.loads(message)
        x = str(data["x"]).encode()
        y = str(data["y"]).encode()
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.sendto(x, (IP, 5005))
        sock.sendto(y, (IP, 5005))


start_server = websockets.serve(connect, IP, 5679)
asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
