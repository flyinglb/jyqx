//m_weapon .....xuanbing1.c
//xuanbing.c

inherit ROOM;

void create()
{
	set("short", "�����Ŷ�");
	set("long",
		"�����������Ŷ������涴��֮�Ͻ�����ʯӢ����״�ᾧ�壬�Ե�\n"
		"ʮ��Ư����ǰ��һ���޴��¯��ǰվ��һλ��������������¯������\n"
		"ʲô���£��Ա߼������δ��������Ŵ�ͷ�ô���һ���ƺ���Ҳ�ղ�\n"
		"���ʲô�������Ա���ϸ�ķ��ż��Ѹոճ�¯�ı��������ֺ��˵�ɱ\n"
		"�����Ǵ���Щ������ɢ�������ġ�\n"

	);
	set("exits", ([
		"out" : __DIR__"xuanbing",
	]));
        set("objects" , ([
               __DIR__"npc/tianjianshi" : 1,

             ]) );
	setup();
	replace_program(ROOM);
}
