int do_rideyz()
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
        ob->move("/d/hangzhou/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road13");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road12");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road11");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road10");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road9");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road8");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road7");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road6");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road5");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road4");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/hongchunqiao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road3");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/hangzhou/road1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/quanzhou/jxnanmen");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/quanzhou/jiaxing");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/quanzhou/qzroad2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/quanzhou/qzroad1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/taishan/yidao1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/taishan/yidao");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/dongmen");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/dongdajie2");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/dongdajie1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/guangchang");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/beidajie1");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/kedian");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·��ҡ���۶�����\n", ({ob}));
        ob->move("/d/city/majiu");
        tell_room(environment(ob),ob->query("name")+"����"+hname+"һ·˳���������ݡ�\n");
        message_vision("\n$N����һת��Ծ����������̬ʮ������������Ҳ��$Nһ��� !\n" ,ob);
        ob->delete_temp("marks/horserent");
        return 1;
}
