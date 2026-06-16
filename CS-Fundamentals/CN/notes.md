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

---

# HTTP vs HTTPS

# HTTP

HTTP = HyperText Transfer Protocol

Used for communication between:

Browser ↔ Server

HTTP sends data in plain text.

Not secure.

Default Port:

80

Example:

http://example.com

---

# Problems with HTTP

Data is not encrypted.

Anyone in the network can read:

- Username
- Password
- Messages

This is called packet sniffing.

---

# HTTPS

HTTPS = HyperText Transfer Protocol Secure

HTTPS is HTTP + SSL/TLS.

Data is encrypted before transmission.

Secure communication.

Default Port:

443

Example:

https://google.com

---

# Advantages of HTTPS

- Encryption
- Authentication
- Data Integrity
- Security

---

# SSL/TLS

SSL/TLS creates secure encrypted communication.

Before data transfer:

Browser and server perform TLS Handshake.

Then encrypted communication starts.

---

# HTTP vs HTTPS

| HTTP | HTTPS |
|--------|--------|
| Not Secure | Secure |
| No Encryption | Encrypted |
| Port 80 | Port 443 |
| Faster | Slightly Slower |
| Vulnerable | Secure |

---

# Example

Login Form

HTTP:

username = ujjwal
password = 1234

Anyone can read data.

---

HTTPS:

username = encrypted
password = encrypted

Cannot be read easily.

---

# Interview Answer

HTTP is a protocol used for communication between browser and server. HTTPS is the secure version of HTTP that uses SSL/TLS encryption to protect data during transmission.

---

# DNS

DNS = Domain Name System

DNS converts:

Domain Name

↓

IP Address

Example:

google.com

↓

142.xxx.xxx.xxx

---

# Why DNS?

Hum humans:

google.com

yaad rakh sakte hain.

Computers:

IP Address

samajhte hain.

DNS acts like a phonebook of the internet.

---

# DNS Lookup Flow

User enters:

google.com

↓

Browser Cache Check

↓

OS Cache Check

↓

DNS Resolver

↓

DNS Server

↓

IP Address Returned

↓

Connection Established

---

# Example

google.com

↓

142.250.xxx.xxx

Browser now connects to that IP.

---

# Interview Answer

DNS converts domain names into IP addresses so that browsers can locate and communicate with servers on the internet.

---

# Memory Trick

google.com

↓

DNS

↓

IP Address

↓

TCP Handshake

↓

HTTPS Handshake

↓

HTTP Request

↓

HTTP Response

↓

Browser Render

---

# Load Balancer

# What is Load Balancer?

A Load Balancer distributes incoming requests across multiple servers.

Purpose:

- prevent server overload
- improve performance
- increase availability
- provide fault tolerance

---

# Example

Without Load Balancer

Client Requests
       |
       v
     Server 1

All traffic goes to one server.

Server may become overloaded.

---

# With Load Balancer

Clients
   |
   v

Load Balancer

 /    |    \
v     v     v

S1    S2    S3

Requests are distributed among servers.

---

# Why Load Balancer?

Benefits:

- High Availability
- Scalability
- Better Performance
- Fault Tolerance

---

# Round Robin Algorithm

Most common algorithm.

Requests are assigned one by one in circular order.

Example:

Servers:

S1
S2
S3

Requests:

R1 → S1
R2 → S2
R3 → S3
R4 → S1
R5 → S2
R6 → S3

Simple and easy.

---

# Advantages

- Easy implementation
- Equal distribution

---

# Disadvantages

Does not consider server load.

Example:

S1 may already be busy,
but still receives requests.

---

# Least Connections Algorithm

Request goes to server with minimum active connections.

Example:

Current Connections

S1 = 10

S2 = 3

S3 = 5

New Request

↓

Assigned to S2

Because S2 has least load.

---

# Advantages

- Better load distribution
- Suitable for varying workloads

---

# Disadvantages

Need to track active connections.

---

# Real World Example

Google

Amazon

Netflix

Facebook

Use load balancers to distribute millions of requests.

---

# Interview Question

Why use Load Balancer?

Answer:

A Load Balancer distributes incoming traffic among multiple servers to improve performance, availability, scalability, and fault tolerance.

---

# Interview Question

Round Robin vs Least Connections

Round Robin:

Request assigned sequentially.

Least Connections:

Request assigned to server with minimum active connections.

---

# Memory Trick

Load Balancer

↓

Distribute Traffic

↓

Round Robin

Equal Rotation

↓

Least Connections

Least Busy Server

---

# REST API

REST = Representational State Transfer

REST API allows communication between:

Client ↔ Server

Examples:

- Mobile App ↔ Backend
- React Frontend ↔ Backend
- Browser ↔ Server

---

# HTTP Methods

## GET

Used to fetch data.

Example:

GET /users

Response:

List of users

---

## POST

Used to create data.

Example:

POST /users

Creates new user.

---

## PUT

Used to update entire resource.

Example:

PUT /users/1

Updates complete user.

---

## DELETE

Used to delete resource.

Example:

DELETE /users/1

Deletes user.

---

# GET vs POST vs PUT vs DELETE

GET

- Read Data
- No Modification

POST

- Create Data

PUT

- Update Existing Data

DELETE

- Remove Data

---

# Example

User Resource

GET /users/1

Returns user details.

---

POST /users

Creates user.

---

PUT /users/1

Updates user.

---

DELETE /users/1

Deletes user.

---

# HTTP Status Codes

## 200 OK

Request successful.

Example:

Data fetched successfully.

---

## 201 Created

Resource created successfully.

Example:

New user created.

---

## 400 Bad Request

Client sent invalid request.

---

## 401 Unauthorized

Authentication required.

Example:

Login required.

---

## 403 Forbidden

User authenticated but not allowed.

---

## 404 Not Found

Resource not found.

Example:

User does not exist.

---

## 500 Internal Server Error

Problem on server side.

---

# Status Code Categories

1xx → Informational

2xx → Success

3xx → Redirection

4xx → Client Error

5xx → Server Error

---

# Idempotency

Meaning:

Multiple identical requests produce same result.

---

# Idempotent Methods

GET

Calling:

GET /users/1

100 times

Result remains same.

---

PUT

PUT /users/1

Same update repeated

Result remains same.

---

DELETE

DELETE /users/1

Deleting same resource repeatedly

Final state remains deleted.

---

# Non-Idempotent Method

POST

POST /users

Called 5 times

Creates 5 users.

Different result every time.

---

# Interview Questions

What is REST API?

REST API is an architectural style that enables communication between client and server using HTTP methods.

---

What is Idempotency?

An operation is idempotent if performing it multiple times gives the same final result.

---

# Memory Trick

GET

Read

↓

POST

Create

↓

PUT

Update

↓

DELETE

Delete

--- 