/*
- clone "update" branch for apply this repo changes:
>git clone -b update https://github.com/Mainvooid/asio2.git
*/

#ifndef __ASIO2_HPP__
#define __ASIO2_HPP__

#if defined(_MSC_VER) && (_MSC_VER >= 1200)
#pragma once
#endif // defined(_MSC_VER) && (_MSC_VER >= 1200)

// If you don't want to use boost in your project,you need to define ASIO_STANDALONE.
// But you can't use http and websocket at the same time.If you want to use http and 
// websocket, you must use boost, and then you have to turn ASIO_STANDALONE off.
#ifndef ASIO_STANDALONE
#define ASIO_STANDALONE
#endif

// If you want to use the ssl, you need to define ASIO2_USE_SSL.
// When use ssl,on windows need linker "libssl.lib;libcrypto.lib;Crypt32.lib;", on 
// linux need linker "ssl;crypto;"
//#define ASIO2_USE_SSL

#if defined(ASIO_STANDALONE) && !defined(ASIO_HEADER_ONLY)
#define ASIO_HEADER_ONLY
#endif

// the tests trigger deprecation warnings when compiled with msvc in C++17 mode
#if defined(_MSVC_LANG) && _MSVC_LANG > 201402
// warning STL4009: std::allocator<void> is deprecated in C++17
#define _SILENCE_CXX17_ALLOCATOR_VOID_DEPRECATION_WARNING
#define _SILENCE_CXX17_ITERATOR_BASE_CLASS_DEPRECATION_WARNING
#define _SILENCE_CXX17_ADAPTOR_TYPEDEFS_DEPRECATION_WARNING
//#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#endif

#ifdef _WIN32
#include <SDKDDKVer.h> //for #include<asio/asio.hpp> _WIN32_WINNT warning
#endif

#include <asio2/base/timer.hpp>
#include <asio2/tcp/tcp_client.hpp>
#include <asio2/tcp/tcp_server.hpp>
#include <asio2/udp/udp_client.hpp>
#include <asio2/udp/udp_server.hpp>
#include <asio2/udp/udp_cast.hpp>
#include <asio2/rpc/rpc_client.hpp>
#include <asio2/rpc/rpc_server.hpp>
#include <asio2/icmp/ping.hpp>
#include <asio2/scp/scp.hpp>

#if defined(ASIO2_USE_SSL)
	#include <asio2/tcp/tcps_client.hpp>
	#include <asio2/tcp/tcps_server.hpp>
#endif

#ifndef ASIO_STANDALONE
	#include <asio2/http/http_client.hpp>
	#include <asio2/http/http_server.hpp>
	#include <asio2/http/ws_client.hpp>
	#include <asio2/http/ws_server.hpp>
	#include <asio2/http/httpws_server.hpp>
	#if defined(ASIO2_USE_SSL)
		#include <asio2/http/https_client.hpp>
		#include <asio2/http/https_server.hpp>
		#include <asio2/http/wss_client.hpp>
		#include <asio2/http/wss_server.hpp>
		#include <asio2/http/httpwss_server.hpp>
	#endif
#endif // ASIO_STANDALONE

#endif // !__ASIO2_HPP__
