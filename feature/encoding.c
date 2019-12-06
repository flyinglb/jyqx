// for encoding format conversion.
// mon 5/11/98
// Modified by Eatdami@MX (10/01/2000)

// GB:   0
// BIG5: 1
nosave int chinese_encoding=0;

int query_encoding() 
{
	return chinese_encoding;
}

void set_encoding(int encoding) 
{
	chinese_encoding=encoding;
}             
