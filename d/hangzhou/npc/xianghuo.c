// xianghuo.c ������

inherit NPC;

void create()
{
        set_name("������", ({ "xianghuo daoren","daoren","xianghuo"}));
        set("age", 32);
        set("gender", "����");
        set("long",
"�䵱���ķ����ĵ��ӡ�\n");
        set("attitude", "peaceful");
        set("str", 24);
        set("dex", 16);
        set("combat_exp", 50000);
        set("shen_type", 1);

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("parry", 60);
        set_skill("force", 60);
        set_temp("apply/attack", 40);
        set_temp("apply/defense", 40);
        set_temp("apply/damage", 20);
        set_temp("apply/armor", 30);
        set("chat_chance", 5);
        set("chat_msg", ({
                "�����˰��־ٵ�����ǰ���������Ǯ�ɣ������ٷ�\n",
                (: random_move :)
        }) );
        create_family("�䵱��", 4, "����");
        setup();
        carry_object("/clone/weapon/changjian");
        carry_object("/d/wudang/obj/whiterobe")->wear();
}
