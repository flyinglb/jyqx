//      kufang.c �ⷿ
//      Designed by secret (����)
//      97/04/09

inherit ROOM;
void create()
{
	set("short","�ⷿ");
	set("long",@LONG
���������䳡�Աߵ�С�ⷿ�������ܲ�ͨ�磬ֻ��һ
˿���ߴ�����С����Ͷ�������������Щ���õ���������
��ѩɽ�����ճ�������Ҫ�õ��ı�����
LONG );
	set("exits",([
		"east" : __DIR__"chang",
	]));
	set("objects", ([
		"/clone/weapon/zhujian" : random(4),
		"/clone/weapon/gangdao" : random(4),
		__DIR__"obj/mugun" : random(4),
		__DIR__"obj/falun" : random(4),
	]));
//	set("no_clean_up", 0);
	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
	int i, w, x, y, z;
	object *inv;
	inv = all_inventory(me);
	i = sizeof(inv);
	for (i = 0; i < sizeof(inv); i++)
	{
		if (inv[i]->query("id") == "zhujian") w++;
		if (inv[i]->query("id") == "fa lun") x++;
		if (inv[i]->query("id") == "mu gun") y++;
		if (inv[i]->query("id") == "blade") y++;
	}
	if (w>1 || x>1 || y>1 || z>1)
                return notify_fail("��λ" + RANK_D->query_respect(me) + "������̰�ģ�ÿ������һ�Ѿ͹�����\n");
        return ::valid_leave(me, dir);
}
