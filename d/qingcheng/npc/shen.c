// shen.c

inherit NPC;

void create()
{
        set_name("���˿�", ({ "shen renjun", "shen", "renjun" }));
        set("gender", "����");
        set("age", 25);
        set("long", "�����Ǻͼ���ͨ���ϲ�������˿���\n");

        set("combat_exp", 70000);
        set("shen_type", -1);

        set_skill("sword", 70);
        set_skill("pixie-sword", 70);
        set_skill("unarmed", 70);
        set_skill("dodge", 70);
        set_skill("parry", 70);
        map_skill("parry", "pixie-sword");
        map_skill("sword", "pixie-sword");
        create_family("�����", 6, "����");
        setup();
        carry_object("/clone/weapon/changjian")->wield();
        carry_object("/d/wudang/obj/bluecloth")->wear();
}

