function isEmbedded = swichSimulationMode( simulationMode )

    blockHandle = find_system('Vector_Control_Lib', 'FindAll', 'on',  'IncludeCommented', 'on', 'Type', 'Block');

    switch simulationMode
        case 'Emb'
            for i = 1:length( blockHandle )
                blockColor = get_param(blockHandle(i),'BackgroundColor');

                if strcmp(blockColor, 'green')
                    set_param(blockHandle(i),'Commented','on')
                end

                if strcmp(blockColor, 'lightBlue')
                    set_param(blockHandle(i),'Commented','off')
                end
            end
            isEmbedded = boolean(1);
        case 'Sim'
            for i = 1:length( blockHandle )
                blockColor = get_param(blockHandle(i),'BackgroundColor');

                if strcmp(blockColor, 'green')
                    set_param(blockHandle(i),'Commented','off')
                end

                if strcmp(blockColor, 'lightBlue')
                    set_param(blockHandle(i),'Commented','on')
                end
            end
            isEmbedded = boolean(0);
    end
end