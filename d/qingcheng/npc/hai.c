// yu.c

inherit NPC;

void create()
{
        set_name("��׺�", ({ "yu canghai", "yu", "canghai" }));
        set("gender", "����");
        set("age", 52);
        set("long", "�����ΰ�С�������������أ�ٲȻһ�ɴ���ʦ����\n");
        set("class", "taoist");

        set("combat_exp", 800000);
        set("shen_type", -1);

        set_skill("sword", 80);
        set_skill("pixie-sword", 80);
        set_skill("unarmed", 80);
        set_skill("dodge", 80);
        set_skill("parry", 80);
        map_skill("parry", "pixie-sword");
        map_skill("sword", "pixie-sword");
        create_family("�����", 7, "����");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}


