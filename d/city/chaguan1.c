// Room: /d/city/chaguan1.c

inherit CHATTING_ROOM;

void create()
{
        set("short", HIM"����"NOR);
        set("long", @LONG
����ǲ����Ĳ��ҡ����ﲼ�õúܵ��ţ�����������Ƣ�����ܵ�
���һ��Ʒ�裬һ�߸�̸���ۡ�����ϸһ�����ƺ�̸���ǽ����ϸշ���
��һ�����£��㲻�ɵô��˹�ȥ��������������
LONG
        );
//        set("resource/water", 1)
	set("exits", ([
		"east"  : __DIR__"chaguan",
	]));
        setup();
        "/clone/board/chatroom1_b"->foo();
}
