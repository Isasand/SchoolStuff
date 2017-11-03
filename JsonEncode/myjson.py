import re
string = "" 

#all test cases passes yay

def json_master(input):
    global string 
    string = "" 
    json_encode(input)
    return string 

def json_encode( data ):
    global string
    
    if isinstance( data, bool ):
        if data:
            string += "true"
        else: 
            string +="false"
            
    elif isinstance( data, ( int, float ) ):
        string += str(data)
    
    elif isinstance( data, str ):
        string += '"'+''.join([(re.sub('\n', '\\\\n', x)) for x in data])+'"'
       
    elif isinstance( data, list ):
        string +='['+','.join([(json_master(x)) for x in data])+']'
        
    elif isinstance( data, dict ):
        string += "{"
        for k,v in data.items():
            string +='"'+(k)+'"' +":" + "".join(json_master(v))+","
        string = string[:-1] + "}"
        
    else:
        # All other types do not  need to be implemented - it is OK that they raise an error
        raise TypeError( "%s is not JSON serializable" % repr( data ) )
    return