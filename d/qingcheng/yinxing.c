// Room: /qingcheng/yinxing.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
��ǰ���������ഫΪ����ʦ��ֲ���߿�ʮ���ɣ���Χ�ߡ�����
�ϱ���֦Ҷ���裬�Ը����ơ�
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"east"     : __DIR__"tianshidong",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

