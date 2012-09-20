# qtxmlrpc-fork
## Author
    Original:
    see [ http://code.google.com/p/qtxmlrpc/ ]
    
    Changed:
    Yohei.Sekiguchi <ysekiguchi.zzz@gmail.com> 

# Description of Software
This software is XML-RPC library, based on the Qt library.
This has the following changes.
(Original version is "http://code.google.com/p/qtxmlrpc/")
 
* You can specify a function to be called from the name of the method of XMLRPC.

```
srv->registerSlot( this, SLOT( paramTestRequestReceived(QVariant) ), "example.onParamTest" );
                                                                      ^^^^^^^^^^^^^^^^^^^
```

```
 XML-RPC method    : example.onParamTest
 Program Function  : paramTestRequestReceived
```

---
### original version

```
srv->registerSlot( this, SLOT( paramTestRequestReceived(QVariant) ));
                               ^^^^^^^^^^^^^^^^^^^^^^^^
```

```
 XML-RPC method    : paramTestRequestReceived
 Program Function  : paramTestRequestReceived
```
it must be same.

---

## License
    It is based on the original.

