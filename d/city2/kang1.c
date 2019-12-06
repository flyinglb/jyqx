// Room: /city2/kang1.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
һ�������ûʵĴ�լԺ�����������ǰ����ͷ�ߴ��ʯʨ��
��ס�˴������ࡣ�����д����������أ��䱸ɭ�ϡ����Ϲ�����
����������Ȼд�Ŵ��ġ������֡�
LONG );
	set("exits", ([
		"south" : __DIR__"wangfu3",
		"north" : __DIR__"kang2",
	]));
	set("objects", ([
		"/d/huanggon/npc/shiwei" : 2,
	]));
//	set("no_clean_up", 0);
	setup();
}

int valid_leave(object me, string dir)
{
    int i;
    object *inv;
    if(dir=="north")
    {
     if( this_player()->query("meili")>50 )
     {
        inv = all_inventory(me);
        for(i=sizeof(inv)-1; i>=0; i--)
            if(inv[i]->query("weapon_prop")&& (inv[i]->query("equipped")))
		if(objectp(present("shi", environment(me)))&&living(present("shi", environment(me))))
                    return notify_fail("������ǰ��ס�㣬����˵������λ" +
                        RANK_D->query_respect(me) + "����±��С�\n"
                        "����Խ������������ֱֳ��С�\n");
        return ::valid_leave(me, dir);
     }
     else
     {
         if(objectp(present("shi", environment(me)))&&living(present("shi", environment(me))))
            return notify_fail("������ס�������������Ϊ����˭����һ��Ѱ�����գ��ѵ���������������ˣ���\n����" + RANK_D->query_rude(me) +"����ҹ�Զ�������Ȼ����Ҳ���������\n");
     }
    }	
    return ::valid_leave(me, dir);
}
