int do_ridets()
{
        string hname;
        object ob = this_player();
        if (ob->query_temp("marks/horserent")!=1 && ob->query("age")>14)
        {
                command("chat ��������"+ob->query("name")+
                "���"+RANK_D->query_rude(ob)+"��͵��\n");
                return 1;
        }
        switch (random(3))
        {
                case 1:
                        hname=MAG"������"NOR;
                        break;
                case 2:
                        hname=RED"�����"NOR;
                        break;
                default:
                        hname=HIY"������"NOR;
                        break;
        }
        message_vision(
"������ָ�$Nǣ��һƥ"+hname+"��$N����Ծ��������������������·������һ��
���: �����ޡ�\n"NOR , ob );
        message_vision("\nֻ��$N������һ�У�"+hname+"�����͵��ȥ��\n",ob);
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/city/xidajie1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/city/xidajie2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/city/ximen");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/city/ximenroad");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/xxroad1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/xxroad2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/xxroad3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/jiayuguan");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/silk1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/silk2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/silk3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/silk4");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/shanjiao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/beijiang");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n");
        ob->move("/d/xingxiu/majiu");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳��������ɽ���µı���С��\n");
        message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��塣\n",ob);
        tell_room(environment(ob),hname+"һ·���۵�����ɽ���¡�\n");
        ob->delete_temp("marks/horserent");
        return 1;
}
