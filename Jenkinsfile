pipeline {
    agent {
        label 'linux'
    }
    environment { 
        REPO_PRUEBAS = 'https://github.com/Lou2714/PruebasCatch2.git'
        REPO_PRUEBAS_CREDENTIALS = credentials('ProbandoJenkins')
    }
    stages{
        stage('Preparing enviorement'){
            steps{
                checkout scm
            }
        }
        stage('Getting test repository'){
            steps{
                dir('PruebasCatch2'){
                    git(
                        url: 'https://github.com/Lou2714/PruebasCatch2.git',
                        credentialsId: 'ProbandoJenkins',
                        branch: 'main'
                    )
                }
                
            }
        }
        stage('Checking directory'){
            steps{
                dir('PruebasCatch2'){
                    sh 'ls -la'
                }
            }
        }
        stage('Checking credentials'){
            steps{
                sh 'echo "Service user is $REPO_PRUEBAS_CREDENTIALS_USR"'
                sh 'echo "Service password is $REPO_PRUEBAS_CREDENTIALS_PSW"'
            }
        }
    }
    post { 
        always { 
            echo 'I will always say Hello again!'
        }
    }
}