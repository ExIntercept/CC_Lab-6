FROM python:3.9-slim

WORKDIR /app

RUN cat << 'EOF' > server.py
import http.server
import socketserver
import socket

class Handler(http.server.BaseHTTPRequestHandler):
    def do_GET(self):
        self.send_response(200)
        self.send_header("Content-type", "text/plain")
        self.end_headers()
        self.wfile.write(f"Served by backend: {socket.gethostname()}".encode())

PORT = 8080
with socketserver.TCPServer(("", PORT), Handler) as httpd:
    httpd.serve_forever()
EOF

EXPOSE 8080

CMD ["python", "server.py"]
