// cunmin.c
// by victori

inherit NPC;
string *first_name = ({"��", "��", "Ǯ", "��","��"});
string *name_words = ({"����","����","���","����","��ɵ"});


void create()
{
        string name;
        name = first_name[random(sizeof(first_name))];
        name += name_words[random(sizeof(name_words))];


        set_name(name,({"cun min"}));
        set("gender", "����" );
        set("age", 32);
        set("long", "���Ǹ�����ͨͨ�������ˣ��Ϻ�����ţ����ϳ����˺����ϼ롣\n");

        set("max_qi", 200);
        set("shen_type", 1);
        set("str", 17);
        set("dex", 20);
        set("con", 18);
        set("int", 19);
        set("combat_exp", 500);
        set_temp("apply/attack", 5);
        set_temp("apply/defense", 15);
        set("attitude", "peaceful");
        setup();
        carry_object("/d/city/obj/cloth")->wear();
}

