inherit F_SAVE;
inherit ITEM;
#define NEWS "/data/board/news_b"
void create()
{
	set_name("���ŷ�����",({"news"}));
	set("unit","��");
	setup();
}

string query_save_file()
{
	return NEWS;
}

string query_news(string num)
{
	mapping *news,new1;
	int i;
	restore();
	news = query("notes");
	if(!pointerp(news)||sizeof(news)==0)
		write("���󣡲��ܲ�ѯnotes��\n");
	if(stringp(num)&&sscanf(num,"%d",i)==1&&i<=sizeof(news))
		i=((i-1)<0)?0:i-1;
	else
		i=random(sizeof(news));
	new1 = news[i];
	return new1["msg"];
}
