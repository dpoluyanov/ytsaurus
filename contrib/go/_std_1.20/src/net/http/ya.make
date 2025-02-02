GO_LIBRARY()

SRCS(
    client.go
    clone.go
    cookie.go
    doc.go
    filetransport.go
    fs.go
    h2_bundle.go
    h2_error.go
    header.go
    http.go
    jar.go
    method.go
    request.go
    response.go
    responsecontroller.go
    roundtrip.go
    server.go
    sniff.go
    socks_bundle.go
    status.go
    transfer.go
    transport.go
    transport_default_other.go
)

END()

RECURSE(
    cgi
    cookiejar
    fcgi
    httptest
    httptrace
    httputil
    internal
    pprof
)
