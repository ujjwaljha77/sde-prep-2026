# What Happens When You Type google.com?

# Step 1: Browser Cache Check

Browser first checks whether the IP address of google.com is already available in cache.

If found:
- use cached IP

If not found:
- perform DNS lookup

---

# Step 2: DNS Lookup

DNS = Domain Name System

DNS converts:

google.com

into

IP Address

Example:

google.com
↓

142.250.xxx.xxx

Without DNS, computers cannot understand domain names.

---

# Step 3: TCP 3-Way Handshake

Before communication starts, TCP connection is established.

Steps:

1. Client sends SYN
2. Server sends SYN-ACK
3. Client sends ACK

Connection established.

Diagram:

Client
  |
  | SYN
  v
Server
  ^
  | SYN-ACK
  |
Client
  |
  | ACK
  v
Server

---

# Step 4: TLS / HTTPS Handshake

HTTPS creates a secure encrypted connection.

Purpose:

- data encryption
- security
- authentication

Browser verifies server certificate.

Secure connection established.

---

# Step 5: HTTP Request

Browser sends request to Google server.

Example:

GET / HTTP/1.1

Request contains:

- URL
- Headers
- Cookies

---

# Step 6: Server Processing

Google server receives request.

Server:

- processes request
- finds required resources
- prepares response

---

# Step 7: HTTP Response

Server sends response back.

Response contains:

- HTML
- CSS
- JavaScript
- Images

Example:

HTTP/1.1 200 OK

---

# Step 8: Browser Rendering

Browser renders page.

Steps:

- Parse HTML
- Build DOM
- Apply CSS
- Execute JavaScript
- Create Render Tree

---

# Step 9: Page Display

Final webpage appears on screen.

User can now interact with Google.

---

# Complete Flow

Browser Cache
↓

DNS Lookup
↓

TCP 3-Way Handshake
↓

TLS / HTTPS Handshake
↓

HTTP Request
↓

Server Processing
↓

HTTP Response
↓

Browser Rendering
↓

Google Homepage Display

---

# Interview Answer (30 Seconds)

When a user types google.com, the browser first checks cache for the IP address. If not found, DNS converts the domain name into an IP address. Then TCP 3-way handshake establishes a connection, followed by HTTPS/TLS handshake for security. The browser sends an HTTP request, the server processes it and returns an HTTP response. Finally, the browser renders HTML, CSS, and JavaScript, and displays the webpage.

---

# Memory Trick

Cache
↓

DNS
↓

TCP

↓

HTTPS

↓

Request

↓

Response

↓

Render

↓

Display

---

# TCP vs UDP

# TCP

TCP = Transmission Control Protocol

TCP is:

- Connection Oriented
- Reliable
- Ordered

Before sending data:

Connection is established using
TCP 3-Way Handshake.

---

# Features of TCP

- Reliable delivery
- Error checking
- Ordered packets
- Retransmission supported

---

# Example Uses

- Web Browsing (HTTP/HTTPS)
- Email
- File Transfer (FTP)
- Banking Applications

---

# UDP

UDP = User Datagram Protocol

UDP is:

- Connectionless
- Fast
- Unreliable

No handshake required.

---

# Features of UDP

- Faster than TCP
- No retransmission
- No ordering guarantee
- Lower overhead

---

# Example Uses

- Video Streaming
- Online Gaming
- Video Calls
- DNS

---

# TCP vs UDP

| TCP | UDP |
|------|------|
| Connection Oriented | Connectionless |
| Reliable | Unreliable |
| Ordered Delivery | No Order Guarantee |
| Slower | Faster |
| Higher Overhead | Lower Overhead |
| Handshake Required | No Handshake |

---

# Interview Question

When should you use TCP?

Use TCP when reliability is important.

Examples:
- Banking
- Login Systems
- File Transfer

---

# Interview Question

When should you use UDP?

Use UDP when speed is important.

Examples:
- Gaming
- Live Streaming
- Video Calls

---

# Memory Trick

TCP

Reliable
Accurate
Slower

UDP

Fast
Lightweight
Unreliable