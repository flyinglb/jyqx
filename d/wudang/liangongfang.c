// liangongfang.c ������
// by Xiang

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
���������������������ҵط��ż������ţ���λ�䵱��������ϥ������
�������
LONG );
        set("exits", ([
                "west" : __DIR__"donglang2",
        ]));
        set("objects", ([
                "/d/village/obj/zhujian" : 3
        ]));
        set("no_fight", 1);
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
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ���񽣾͹�����\n");
        return ::valid_leave(me, dir);
}
