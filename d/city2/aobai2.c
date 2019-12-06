// Room: /city2/aobai2.c


inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ����ס�˴���
���ࡣ�Ŷ�������һ�����ң�д�š����޵�һ��ʿ���ݸ����������֣�����
�йٱ����أ��䱸ɭ�ϡ����Ϲ���������������Ȼд�š������֡�
LONG );
	set("exits", ([
		"east" : __DIR__"aobai1",
		"west" : __DIR__"aobai3",
	]));
	set("objects", ([
		"/d/city/npc/bing" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="west")
    {
     if( this_player()->query("meili")>50 )
        {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop") && (inv[i]->query("equipped")))
		if(objectp(present("bing", environment(me))) &&
                   living(present("bing", environment(me))))
                    return notify_fail("�ٱ���ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "����Խ������������ֱֳ��С�\n");
	return ::valid_leave(me, dir);
        }
     else
     {
         if(objectp(present("guan bing", environment(me)))&&living(present("bing", environment(me))))
            return notify_fail("�ٱ���ס�������������Ϊ����˭����һ��Ѱ�����գ��ѵ���������������ˣ���\n����" + RANK_D->query_rude(me) +"����ҹ�Զ�������Ȼ����Ҳ���������\n");
      }
    }	
return ::valid_leave(me, dir);
}

