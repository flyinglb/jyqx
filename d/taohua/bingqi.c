inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
����һ���ű��������ӡ�����ǹ������ꪵȸ��ֱ������������
���Եı������ϡ��������������ҳ�����Ȼ�Ѿ��þ�û��������
LONG );
	set("exits", ([
		"west" : __DIR__"qianyuan",
	]));
	set("objects", ([
		__DIR__"obj/taojian": 5,
	]) );
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
		if (inv[i]->query("id") == "taomu jian") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ����ľ���͹�����\n");
        return ::valid_leave(me, dir);
}
