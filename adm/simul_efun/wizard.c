// wiz.c

string wizhood(mixed ob)
{
	return SECURITY_D->get_status(ob);
}

int wiz_level(mixed ob)
{
	return SECURITY_D->get_wiz_level(ob);
}

string query_wiz_status(int i) 
{ 
        return SECURITY_D->query_wiz_status(i);
}

int query_wiz_level(string str) 
{ 
        return SECURITY_D->query_wiz_level(str); 
}
