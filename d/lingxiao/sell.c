//LUCAS 2000-6-18
inherit ROOM;

void create()
{
        set("short", "ˮ����");
        set("long", @LONG 
�����������ǵĴ���--ˮ������������ˮ��������������
Ϊ����������ˮ�����ƣ�����Ҫ��������������Ȼ������������
�����������������˳ơ�ˮ���������ϰ�³�������ڹ�̨
��Ц������ͬ�����ּۻ��ۡ�
LONG
        );
        set("no_fight", 1);
        set("no_steal", 1);
        set("no_beg",1);
        set("item_desc", ([
                "paizi" : "ˮ������,ͯ������\n
sell        �� 
buy         ��
redeem      ��
value       ����
",
        ]));
        set("objects", ([
                __DIR__"npc/laoban" : 1,
                __DIR__"npc/dizi" : 1,
        ]));
        set("no_clean_up", 0);
        set("exits", ([
                "west" : __DIR__"iceroad1",
        ]));

        setup();
          replace_program(ROOM);
}

