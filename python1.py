import asyncio
import json
import websockets
import socket

IP1 = "192.168.43.188"
IP2 = "192.168.43.167"


async def connect(websocket, path):
    async for message in websocket:
        data = json.loads(message)
        mess = bytes([data["x"]+100, data["y"]+100])
        print(data["x"], data["y"])
        sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        sock.sendto(mess, (IP2, 5005))


start_server = websockets.serve(connect, IP1, 5679)
asyncio.get_event_loop().run_until_complete(start_server)
asyncio.get_event_loop().run_forever()
