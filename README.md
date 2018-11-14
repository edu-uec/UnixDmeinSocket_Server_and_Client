# Unix Socket Server & Client

## About

Server and Client implementation for ipc (inter process communication)

## Build

`git clone {repo}`

`cd {repo}`

`mkdir build && cd build`

`cmake ..`

`make`

## Run

In `build` dir, in different tab or window of bash for each.

`./unix_socket_server`

`./unix_socket_server`

## Code

### Client

The client code are placed under `src/client`.

`unix_socket_client.hpp` is client class implementation.

`client_main.cpp` is example of class usage.

### Server

...Same

#### Server code detailed

The server_main.cpp is much complicated than client one.

It uses `std::thread` to run server on another therad and `boost::signals2` to implement eventhundler for command arrival from edu.

Below links will be help

- std::thread https://cpprefjp.github.io/reference/thread/thread.html
- boost::signals2 https://boostjp.github.io/tips/signals.html
- boost::bind https://boostjp.github.io/archive/boost_docs/libs/bind.html
- lambda function in cpp https://cpprefjp.github.io/lang/cpp11/lambda_expressions.html
