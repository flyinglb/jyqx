//room: sheyuan.c
inherit ROOM;

void create()
{
	set("short","��԰");
	set("long", @LONG
�����ǰ���ɽׯ����԰������ɽ�Զ��������£�����Ҫ��
���ʾ����Զ��ߡ����������ߣ�ǽ��Ҳ�����ߣ�������Ҳ��
�´����ߣ���֦��Ҳ�������ߣ������㲻�ľ���
LONG );
	set("exits",([
		"west"  : __DIR__"tuyuan",
	]));
	set("outdoors", "baituo");
	set("objects",([
		"/d/shenlong/npc/jinshe" :1,
		"/d/shenlong/npc/dushe" :1,
		"/d/shenlong/npc/fushe" :1,
		"/d/shenlong/npc/qingshe" :1,
		"/d/fuzhou/npc/wubushe" :1,
	]));
	setup();
	replace_program(ROOM);
}

