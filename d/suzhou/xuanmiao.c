// Room: /d/suzhou/xuanmiao.c
// Date: May 31, 98  Java

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
��һ�߽�����ۣ���������������ƣ�����ڶࡣ������
��Ъɽʽ���ݼ���ʮ���ף����иߴ������ʮ���������¶�ƽ
�������ܽ���������ʺ�󣬵���������ש��������������
�����ŵ������ʮ���׵�������������񣬷���ׯ�ϣ������
�ȣ���ʧΪ���̵����еľ�Ʒ��
LONG );
	set("outdoors", "suzhou");
	set("no_clean_up", 0);
	set("exits", ([
		"north"  : __DIR__"xidajie2",
	]));
	setup();
	replace_program(ROOM);
}
