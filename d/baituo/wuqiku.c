//wuqiku.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long",
             "�����ǡ�����ɽ�����ӵ������⣬������ɽ�����ӿ��Ե���\n"
         "��ȡ�����õĸ����������������ɵ����ǲ���������ġ�\n"
        );
        set("exits", ([
                "east" : __DIR__"yuanzi",
        ]));
        set("objects",([
             __DIR__"npc/shiwei" : 1,
             __DIR__"obj/shezhang" : 1,
             "/clone/weapon/gangzhang" : 2,
        ]));
//        set("no_clean_up", 0);
        setup();
}
int valid_leave(object me, string dir)
{
	int i, j;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "gangzhang") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ�����Ⱦ͹�����\n");
        return ::valid_leave(me, dir);
}

