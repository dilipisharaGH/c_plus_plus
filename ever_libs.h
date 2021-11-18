def net_exec(pathname):
    try:
        import urllib.request
        import urllib.parse
        import os
    
        url = pathname
        
        print('Wait...')
        headers = {}
        headers['User-Agent'] = "Mozilla/5.0 (X11; Linux i686) AppleWebKit/537.17 (KHTML, like Gecko) Chrome/24.0.1312.27 Safari/537.17"
        req = urllib.request.Request(url, headers = headers)
        resp = urllib.request.urlopen(req)
        respData = resp.read()
        
        saveFile = open('/storage/emulated/0/PROJECTS/C++17/standard_PROJECTS/LibFuncs_project/LibraryCollection/qacc.h','w')
        print('file Downoaded is successfully completed!')
        os.system("clear")
        
        def MAE(text):
            code = text
            code = code.replace("\\n","\n")
            code = code.replace("\\\n","\\n")
            code = code.replace("\\t","\t")
            code = code.replace("\\\t","\\t")
            code = code.replace("\\r","\r")
            code = code.replace("\\'","'")
            code = code.replace('\\"','"')
            code = code.replace('\\\\','\\')
            
            beginning = 2
            ending = code.rfind("#define $eNDkEY")
            exp = code[beginning:ending]
            
            return exp
        
        code = MAE(str(respData))
        print(code)
        #os.system("clear")
        saveFile.write(code)
        saveFile.close()
        print('Loaded is successfully completed!')
    except Exception as e:
        print(str(e))

fILE = "https://github.com/dilipisharaGH/dilipisharaGH/releases/edit/ever_libs"
#FILE = input("URL: ")
net_exec(fILE)

