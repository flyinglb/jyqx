// bingqif.c
// shilling 97.2

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
�������������һ��Сʯ�ݣ������Ǵ�������ģ��������и����¯
���̵��أ����л���һ��ʯ�����������һЩ�Ѿ�����õı�����
LONG );
	set("exits", ([
		"south" : __DIR__"xiaodao2",
	]));
	set("no_clean_up", 0);
	set("objects", ([
	       __DIR__"obj/blade": 2,
	]));
//	set("no_clean_up", 0);
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
		if (inv[i]->query("id") == "blade") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ�ڸֵ��͹�����\n");
        return ::valid_leave(me, dir);
}
