FROM python:3.9-slim

WORKDIR /app

RUN echo 'import http.server, socketserver, socket
class Handler(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/plain")
        self.end_headers()
        self.wfile.write(f"Served by backend: {socket.gethostname()}".encode())

PORT = 8080
with socketserver.TCPServer(("", PORT), Handler) as httpd:
    httpd.serve_forever()' > server.py

EXPOSE 8080

CMD ["python", "server.py"]
