GO_LIBRARY()

LICENSE(BSD-3-Clause)

SRCS(hkdf.go)

GO_TEST_SRCS(hkdf_test.go)

GO_XTEST_SRCS(example_test.go)

END()

RECURSE(gotest)
