// midao5.c �ܵ�

inherit ROOM;

void create()
{
        set("short", "����ͨ��");
        set("long", @LONG
����һ��ʯ�ң���Լ���Ըо��������Ǳ������Ӳ��ʯ�ڣ���
�Ϻͽ��䶼�ǻҳ�����źþ�û�������ˡ�
LONG );

        set("exits", ([
               "east" : __DIR__"midao4",
               "out"  : __DIR__"neiting",
        ]));
        set("objects", ([
               __DIR__"obj/jiu" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
}

int valid_leave(object me,string dir)
{
        if(dir=="out")
           tell_object(me,"���߳�������ͨ�������صس���������֮�С�\n");
        return ::valid_leave(me,dir);
}

