# qtxmlrpc-fork
## Author
    Yohei.Sekiguchi <ysekiguchi.zzz@gmail.com> 

# Description of Software
This software is XML-RPC library, based on the Qt library.
This has the following changes.
(Original version is "http://code.google.com/p/qtxmlrpc/")
 
* You can specify a function to be called from the name of the method of XMLRPC.

 ** this version

```
srv->registerSlot( this, SLOT( paramTestRequestReceived(QVariant) ), "example.onParamTest" );
                                                                      ^^^^^^^^^^^^^^^^^^^
```

   XML-RPC method      :      Program Function
--------------------------------------------------
"example.onParamTest" --> paramTestRequestReceived

 ** original version

```
srv->registerSlot( this, SLOT( paramTestRequestReceived(QVariant) ), "example.onParamTest" );
                                                                      ^^^^^^^^^^^^^^^^^^^
```

       XML-RPC method      :      Program Function
------------------------------------------------------
"paramTestResuetReceived" --> paramTestRequestReceived

## License
    GNU Lesser GPL

