//neishi.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long",
	     "\n������һ���յ����ķ��䣬���˵ذ�(floor)��ʲôҲû�С�\n"
	);
	set("exits", ([
		"east" : __DIR__"huichunt",
	]));
	set("item_desc", ([
		"floor" : "\n�ذ�ȫ��ľ�Ƶģ��������Щ�ҳ���������һ��ľ��ܸɾ���\n" ,
	]));
	set("no_clean_up", 0);
	setup();
}

void init()
{
        add_action("do_enter", "enter");
        add_action("do_move", "move");
        add_action("do_move", "open");
        add_action("do_knock", "knock");
}


int do_move(string arg)
{
        object me;
        me = this_player();
        if (!arg||arg!="floor") return notify_fail("��Ҫ�ƿ�ʲô��\n");
	message_vision(
		"\n$N�ƿ��ײİ壬ֻ����ৡ���һ��, �ص���ͻȻ�׹�һ����\n"+
		"һ������ٿ�����,���ۡ���һ��������$N��С��,�֡��ۡ���һ�����˳�����\n"+
                "һ�����˴Ӷ���̽��ͷ����������м�ؿ���$Nһ�ۣ������ְѵذ�����ˡ�\n", this_player());
        if((int)this_player()->query("qi")<250) this_player()->die();
        else this_player()->unconcious();
	return 1;
}

int do_knock(string arg)
{
        object me,hole;
	string dir;
        me = this_player();
        if (!arg||arg=="") return 0;
	if( arg=="floor" ) {
		message_vision("\n$N���������õذ壬������࣬�����ƺ��ǿ��ĵġ�\n", this_player());
	}
	if( sscanf(arg, "floor %s", dir)==1 ) 
	{
		if( dir=="3" || dir=="three") {
		if(!objectp(present("hole", environment(me))))
		{
		message_vision("\n$N��ľ�����������������£�ֻ��֨ѽһ����\n"+"������һ˫�ְѵذ��ƿ��ˡ�\n", this_player());
                hole = new("/d/city2/obj/hole");
                hole->move("/d/city2/neishi");
		}
	        }   
		else return notify_fail("\n���������ľ�弸�£����ʲôҲû������\n");
	}		
return 1;
}

int do_enter(string arg)
{
 if( !arg || arg!="floor" ) return 0;
 return notify_fail(" �봩�ذ尡���㲻�����Ŷݼס�\n");
 return 1;
}	

