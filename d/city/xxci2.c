// Room: /d/npc/xianxianci.c

//inherit ROOM;
inherit CHATTING_ROOM;

void create()
{
	set("short", "����������ʦ��");
	set("long",
"�����Ǽ���������ʦ�ĵط���ÿλ�����ﱻ�������ʦ��Ϊ��MUD\n"
"�������ܳ��ġ�����ĥ��Ĺ��ס�������Զ���ᰮ�����������ǡ�̧ͷ\n"
"һ�ź��ң������߸���������Ľ��֣�\n"
"              "HBCYN"                              \n"NOR
"              "HBCYN"        "HIY"���׸�Ϊ����ţ        \n"NOR
"              "HBCYN"                              \n"NOR
	);
	set("exits", ([ /* sizeof() == 1 */
		"down" : __DIR__"xxci1",
	]));
	set("no_fight",1);
        set("no_mask", 1);
	set("objects", ([ /* sizeof() == 1 */
		"/d/npc/eatdami" : 1,
		"/d/npc/byp" : 1,
		"/d/npc/robin" : 1,
		"/d/npc/wind" : 1,
	]));

	setup();
//        replace_program(ROOM);
}
