// ���� by netkill@cctx  98-9-13

int competition(object win,object gainer)
{ 
	int i=1,j=1,w_cpm=0,g_cpm=0;
	string str,w_id,g_id;

	w_id=(string)win->query("id");w_id+="\n";
	g_id=(string)gainer->query("id");g_id+="\n";
	str=read_file("/adm/daemons/ladder",i,1);
	while ( j <=20 && str && !(str=="*end*"))
	 {	
		if ( str == w_id  ) w_cpm=j;
		if ( str == g_id  ) g_cpm=j;
		j++;i=i+2;
		str=read_file("/adm/daemons/ladder",i,1);
	 }
	if (!(w_cpm) && !(g_cpm)) 
	  return j;
	if (!(g_cpm)) return w_cpm;
	if (!(w_cpm)) return g_cpm;
	if (w_cpm > g_cpm ) return g_cpm;
	if (w_cpm < g_cpm ) return w_cpm; 
}

string do_ladder(object win,int w_cpm)
{	int i,j,l=0;
	string use="",str,w_id,w_name;
	w_id=(string)win->query("id")+"\n";
	w_name=(string)win->name()+"\n";
	for (i=1; i<=20; i++ )
	 {	j=i-l;l++;
		str=read_file("/adm/daemons/ladder",i,1);
		if (j == w_cpm)  {use+=w_id;use+=w_name;}
		if (w_id == str) {i++;continue;}
		if(str && !(str=="*end*")) use+=str;
		i++;
		if(str && !(str=="*end*"))
		use+=str=read_file("/adm/daemons/ladder",i,1);
		
		
	 }
	//printf("%s",use);
	return use;
}


	