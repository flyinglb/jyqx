// qinpu.c
inherit ITEM;

void create()
{
        set_name("��ʯ��", ({ "huangshi-pu" ,"pu" ,"book"}));
        set_weight(600);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�����ף�����Ŷ��ţ���
�����Դ����淢��һЩ�����Ķ�����\n"
                        "ԭ������һ�����Ž��������ס�\n");
                set("value", 1000);
                set("material", "paper");
                set("skill", ([
                        "name": "wuyun-jianfa",        // name of the skill
                "exp_required": 100, 
                   "jing_cost": 10,
                  "difficulty": 20,                    // the base int to learn this skill
                   "max_skill": 80
                             ]) );
        }
}

