import socket
def server_program():
        host = socket.gethostname()
        port = 19001
        server_socket = socket.socket()
        server_socket.bind((host, port))
        server_socket.listen(2)
        conn, address = server_socket.accept()
        print("Connection from: " + str(address))
        while True:

                data = conn.recv(1024).decode()
                if not data:
                        break
                else:
                        print("The message recieved from the client is : " + str(data))
                        data=data.upper()
                        print("The message sending back to the client is : " + str(data))
                        conn.send(data.encode())
        conn.close()

if __name__ == '__main__':
        server_program()