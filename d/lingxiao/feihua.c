//LUCAS 2000-6-18
// Room: feihua.c

inherit ROOM;
void create()
{
        set("short","�ɻ���");
        set("long",@LONG 
���������ǵ��������ӣ�����÷Ů���������ϵľ�����¥��
�ɻ��󡣻�����������������������Ψһ��Ů�ԣ�һ��Ϊ���ӣ�
���������ϱ�����ϲ�徻����һ�˶����ڴˡ��˴��ǻ�԰С¥֮
�ϣ�ƾ��������ǧ���÷��ӭѩ���裬��÷Ʈ�㣬�׷׶��¡���
�Ϸ���һ��������ɫ��÷����
LONG);
        set("outdoors", "lingxiao");
        set("exits",([ /* sizeof() == 1 */
            "down"  : __DIR__"huajing",  
        ]));
        set("objects", ([
               __DIR__"npc/hua" : 1,
        ]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);

}

