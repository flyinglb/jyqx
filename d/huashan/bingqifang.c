// bingqifang.c ������

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����ǻ�ɽ�ɵı����������ܷ��⼸�������ܣ������ǻ�ɽ�ɸ�����
ƽʱ�����õ��񽣡�
LONG );
        set("exits", ([
                "west" : __DIR__"square",
        ]));
        set("objects", ([ 
            "/clone/weapon/zhujian" : 4
        ]));
//      set("no_clean_up", 0);
        set("no_fight", 1);

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
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ���񽣾͹�����\n");
        return ::valid_leave(me, dir);
}
