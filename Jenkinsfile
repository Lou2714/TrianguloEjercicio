pipeline {
    agent {
        label 'linux'
    }
    environment { 
        REPO_PRUEBAS = 'https://github.com/Lou2714/PruebasCatch2.git'
        REPO_ESTUDIANTE = 'https://github.com/Lou2714/TrianguloEjercicio.git'
        REPO_PRUEBAS_CREDENTIALS = credentials('ProbandoJenkins')
    }
    stages{
        stage('Checking SCM'){
            steps{
                checkout scm
            }
        }
        stage('Getting test repository'){
            steps{
                git(
                    url: "${REPO_PRUEBAS}",
                    credentialsId: 'ProbandoJenkins',
                    branch: 'main'
                )
                script{
                    def repoURL = sh(script: "echo ${REPO_PRUEBAS}", returnStdout: true).trim()
                    def reponame = repoURL.split('/').last().replace('.git', '')
                    echo "reponame"
                }
            }
        }
        stage('Checking directoryx2'){
            steps{
                sh '''
                    cd Repositorios
                    pwd && ls -la
                '''
            }
        }
        stage('Debug') {
            steps {
                sh 'pwd && ls -la'
            }
        }
    }
    post { 
        always { 
            cleanWs()
            echo 'I will always say Hello again!'
        }
    }
}