// Room: /qingcheng/gulongqiao.c
// Date: Frb.20 1998 by Java

inherit ROOM;
void create()
{
	set("short", "������");
	set("long", @LONG
�����ڹ������ϡ������ұ���һ�����Ѳۡ����ʮ�������
���������ɣ���˵������ʦ��ħʱ�Աʻ�ɽ�������ɼҺۼ���
LONG );
        set("outdoors","qingcheng");
	set("exits", ([
		"northup"   : __DIR__"zushidian",
		"southdown" : __DIR__"tianshidong",
	]));
        set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}

