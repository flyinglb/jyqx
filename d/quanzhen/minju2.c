// minju2.c ���
// By Lgg,1998.10

inherit ROOM;

void create()
{
        set("short", "���");
        set("long", @LONG
����һ����é�ݴ�ķ��ݣ���ͽ�ıڣ��ݽǵ��׸��ǿյģ�������
��ˮ��Ҳ�ǿյġ�����ȱ�첲���ȵ����ο�ǽ���š����������Ѿ�����
����ֵǮ�Ķ���ȫ�������ˡ�
LONG
        );
        set("exits", ([
                "south" : __DIR__"xijie",
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}
