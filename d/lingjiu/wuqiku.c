//ROOM: wuqiku.c

inherit ROOM;

void create()
{
        set("short", "ޤ����");
        set("long",@LONG
���ǡ����չ������ӵı����⣬�㻷�����ܣ�����ǽ��Ƕ���˸�ʽ��
������ϸһ����ԭ����ǽ���ھ������������֮�οٳ����ӣ����о�����
���ڡ��㲻�ɰ��ޣ����þ��µ���ͷ����
LONG );
        set("exits", ([
            "east" : __DIR__"changl5",
        ]));
        set("objects",([
          "/d/village/obj/zhujian" : 4,
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
		if (inv[i]->query("id") == "zhujian") j++;
	}
	if (j > 1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�����һ���񽣾͹�����\n");
        return ::valid_leave(me, dir);
}
