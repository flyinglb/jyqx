// huixinshi.c

inherit ROOM;

void create()
{
        set("short", "����ʯ");
        set("long", @LONG
�����ƺ��ʯ����ɽ��ɽ·���˶�����ǰ��ɽ���ն�ʯ�¼����խ
խ��ʯ������������������������б�������˲�������������ǰ�С�����
�´�ʯ��·����ʯ��˽�������ʯ������ȥɽ�����գ��ο����ˣ��͸û�
ͷ�ˡ�
LONG );
        set("exits", ([ /* sizeof() == 2 */
            "westdown" : __DIR__"qingke",
            "eastup"   : __DIR__"qianchi",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "xx" );

        setup();
        replace_program(ROOM);
}
